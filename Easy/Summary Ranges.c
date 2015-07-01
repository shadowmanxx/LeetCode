/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    
    if(nums == NULL || numsSize < 1)
        return NULL;
    
    char tmpBuf[256];
    char **pBuf = NULL;
    unsigned int NumWrited = 0;
    unsigned int Slowp,Quickp;

    pBuf = (char**)malloc(sizeof(char*) * numsSize);
    Slowp = 0;
    Quickp = 1;
    
    *returnSize = 0;
    while(Slowp < numsSize)
    {
        while(Quickp < numsSize && nums[Quickp] - nums[Quickp-1] == 1)  Quickp++;
        
        if(Slowp < Quickp - 1)
        {
            NumWrited = sprintf(tmpBuf,"%d->%d%c",nums[Slowp],nums[Quickp-1],'\0');
            pBuf[*returnSize] = (char*)malloc(sizeof(char) * (NumWrited));
            memcpy(pBuf[*returnSize] , tmpBuf, NumWrited);
        }
        else
        {
            NumWrited = sprintf(tmpBuf,"%d%c",nums[Slowp],'\0');
            pBuf[*returnSize] = (char*)malloc(sizeof(char) * (NumWrited));
            memcpy(pBuf[*returnSize] , tmpBuf, NumWrited);
        }
        
        ++(*returnSize);
        Slowp = Quickp;
        Quickp++;
    }
    
    return pBuf;
}
