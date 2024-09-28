#include "los_config.h"
#include "los_membox.h"
#include <stdlib.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

VOID Example_StaticMem(VOID)
{
    UINT32 *mem = NULL;
    UINT32 blkSize = 10;
    UINT32 boxSize = 100;
    UINT32 boxMem[1000];
    UINT32 ret;

    ret = LOS_MemboxInit(&boxMem[0], boxSize, blkSize);
    if(ret != LOS_OK) {
        printf("�ڴ�س�ʼ��ʧ��!\n");
        return;
    } else {
        printf("�ڴ�س�ʼ���ɹ�!\n");
    }
    
    /*�����ڴ��*/
    mem = (UINT32 *)LOS_MemboxAlloc(boxMem);
    if (NULL == mem) {
        printf("�ڴ����ʧ��!\n");
        return;
    }
    printf("�ڴ����ɹ�\n");

    /*��ֵ*/
    *mem = 828;
    printf("*mem = %d\n", *mem);

     /*����ڴ�����*/
     LOS_MemboxClr(boxMem, mem);
     printf("����ڴ����ݳɹ�\n *mem = %d\n", *mem);

    /*�ͷ��ڴ�*/
    ret = LOS_MemboxFree(boxMem, mem);
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
#endif /* __cplusplus */
#endif /* __cplusplus */
