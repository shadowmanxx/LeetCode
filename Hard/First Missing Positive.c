int firstMissingPositive(int* A, int numsSize) {
    
if(numsSize ==0||A==NULL)
      return 1;
    //把元素放入正确的位置，例如1放在A[0]，2放在A[1]...
    for(int i = 0;i<numsSize;i++)
    {
      while(A[i]!=i+1)
      {
        if(A[i]>=numsSize ||A[i]<=0 ||A[i]==A[A[i]-1])
          break;
        int temp = A[i];
        A[i] = A[temp-1];
        A[temp-1] = temp;
      }
    }
    
    for(int i = 0;i<numsSize;i++)
    {
      if(A[i]!=i+1)
        return i+1;
    }
    return numsSize+1;

}
