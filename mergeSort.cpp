int* merge(int leftArr[], int rightArr[]){   //smallest to largesr order
  int leftFrontIndex = 0;
  int rightFrontIndex = 0;
  int leftArrSize = sizeof(leftArr)/sizeof(leftArr[0]);
  int rightArrSize = sizeof(rightArr)/sizeof(rightArr[0]);
  int* sortedArray = new int[rightArrSize + leftArrSize];
  int index = 0;
  while(leftFrontIndex < leftArrSize && rightFrontIndex < rightArrSize){
    if(leftArr[leftFrontIndex] < rightArr[rightFrontIndex]){
      sortedArray[index] = leftArr[leftFrontIndex];
      leftFrontIndex++;
      index++;
    }
    else{
      sortedArray[index] = rightArr[rightFrontIndex];
      rightFrontIndex++;
      index++;
    }
  }
  //after the while loop, at least one array is empty
  while(rightFrontIndex < rightArrSize){
    sortedArray[index] = rightArr[rightFrontIndex];
    index++;
    rightFrontIndex++;
  }
  while(leftFrontIndex < leftArrSize){
    sortedArray[index] = leftArr[leftFrontIndex];
    index++;
    leftFrontIndex++;
  }
  
  //copy things from sorted Array to the pass
  return sortedArray;

    
  
}
