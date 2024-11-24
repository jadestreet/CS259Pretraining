#include <stdio.h>
#include <ucontext.h>

typedef struct {
    ucontext_t uc;
    stack_t stck[1024];
} Task_t;

void create_task(Task_t *t, ucontext_t *link, void (*pf)()) 
{
    getcontext(&t->uc);
    t->uc.uc_link = link;
    t->uc.uc_stack.ss_sp = t->stck;
    t->uc.uc_stack.ss_size = sizeof(t->stck);
    makecontext(&t->uc, pf, 0);
} 

/*void cosa()                                        *
{
    printf("guau!\n");
}
                                                     *Forma mas precaria hecha en clase
int main()
{
    Task_t tcosa, tmain;
    getcontext(&tmain.uc);
    create_task(&tcosa, &tmain.uc, cosa);
    swapcontext(&tmain.uc, &tcosa.uc);               *
    printf("chau\n");
    return 0;
}
*/

Task_t tf, tg, tmain;

void f() 
{
    int i;
    for(i = 0; i < 10000; i++) {
        printf("%d ", i);
        swapcontext(&tf.uc, &tg.uc);
    } 
} 

void g() 
{
    double d;
    for(d = 0; ; d += 0.0001) {
        printf("%f ", d);
        swapcontext(&tg.uc, &tf.uc);
    }    
}

int main() 
{
    getcontext(&tmain.uc);
    create_task(&tf, &tmain.uc, f);
    create_task(&tg, &tmain.uc, g);
    swapcontext(&tmain.uc, &tf.uc);
    return 0;
}    

