#include "los_config.h"
#include "los_memory.h"
#include <stdlib.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#define TEST_POOL_SIZE (2*1024*1024)
UINT8 g_testPool[TEST_POOL_SIZE];

VOID Example_DynMem(VOID)
{
    UINT32 *mem = NULL;
    UINT32 ret;

    ret = LOS_MemInit(g_testPool, TEST_POOL_SIZE);
    if (LOS_OK  == ret) {
        printf("�ڴ�س�ʼ���ɹ�!\n");
    } else {
        printf("�ڴ�س�ʼ��ʧ��!\n");
        return;
    }

    /*�����ڴ�*/
    mem = (UINT32 *)LOS_MemAlloc(g_testPool, 4);
    if (NULL == mem) {
        printf("�ڴ����ʧ��!\n");
        return;
    }
    printf("�ڴ����ɹ�\n");

    /*��ֵ*/
    *mem = 828;
    printf("*mem = %d\n", *mem);

    /*�ͷ��ڴ�*/
    ret = LOS_MemFree(g_testPool, mem);
    if (LOS_OK == ret) {
        printf("�ڴ��ͷųɹ�!\n");
    } else {
        printf("�ڴ��ͷ�ʧ��!\n");
    }

    return;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

