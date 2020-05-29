#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

//Cuando se ejecuta la llamada al sistema conteo, se ejecuta la función conteo 
int
sys_conteo(void)
{
	return conteo();
}

int sys_date(void) //Cuando se ejecuta la llamada al sistema fecha, se pone el cmostime a la variable r
{
    struct rtcdate *r;
    if(argptr(0, (void*)&r, sizeof(r)) < 0)
    return -1;
    cmostime(r);
    return 0;
}

//Cuando se ejecuta la llamada al sistema contar, se ejecuta la función contar con el valor del sid(que es el nombre que le dí para system call id)
int
sys_contar(void)
{
  int sid;
  if(argint(0, &sid) < 0)
    return -1;
  return contar(sid);
}
