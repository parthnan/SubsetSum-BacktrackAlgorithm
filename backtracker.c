#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX_CARDS 1000000
int index=0;

void quicksort(int sort[],int left,int right){
	if(left >= right){
		return;
	}
	int i=left;
	int j=right;
	int k;
	k=sort[left];
	while(i<j){
		while(i<j&&k<=sort[j]){
			j--;
		}
		sort[i]=sort[j];
		while(i<j&&k>=sort[i]){
			i++;
		}
		sort[j]=sort[i];
	}
	sort[i]=k;
	quicksort(sort,left,i-1);
	quicksort(sort,i+1,right);
}

void merge(int arr[], long l, long m, long r)
{
    long i, j, k;
    long n1 = m - l + 1;
    long n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
} 
void mergeSort(int arr[], long l, long r)
{
    if (l < r)
    {  
        long m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
void printArray(int *arr, long l)
{
	long i;
    for(i=0;i<l;i++)
    {  
        printf("%d   %d\n",i,arr[i]);
    }
}
void fillSums(int *arr,int *sums,int start,int sum,long length)
{
	if(index==(long)pow(2,length))
		index=0;
	if(length == start)
    {
		sums[index]=sum;
		index++;
        return;
    }
    int value = sum + arr[start];
    fillSums(arr, sums,start + 1, value,length);
    fillSums(arr, sums,start + 1, sum,length);
}

int main(){
  clock_t t1,t2;
  int i,j,n,k,found=0,ans=0;
  int *allcard=(int *)calloc(MAX_CARDS,sizeof(int));
  for (i=0;i<MAX_CARDS;i++){
	allcard[i]=(rand()%MAX_CARDS);
  }
  printf("Enter number of Cards to be chosen:\n");
  scanf("%d",&n);
  int half=(int)(n+1)/2;
  long combi=(long)pow(2,half);
  int *card=(int *)calloc(half,sizeof(int));
  int *card2=(int *)calloc(half,sizeof(int));
  int *cardsums=(int *)calloc(combi,sizeof(int));
  int *cardsums2=(int *)calloc(combi,sizeof(int));
  srand(time(0));
  for (i=0;i<half;i++){
	j=rand()%MAX_CARDS;
    card[i]=allcard[j];
	if(n%2==1&&i==half-1){
		card2[i]=0;
	}
	else{
		j=rand()%MAX_CARDS;
		card2[i]=allcard[j];
	}
  }
  for(i=0;i<half;i++)
  {
	  allcard[i]=card[i];
	  allcard[i+half]=card2[i];
  }
  k=rand()%n+1;
  for(i=0;i<k;i++)
  {
	  j=rand()%n;
	  if(allcard[j]>0)
	  {
		ans+=allcard[j];
		allcard[j]=0;
	  }
  }
  free(allcard);
  printf("Cards Chosen by Millionaire are(0=non existent card):\n");
  printArray(card,half);
  printArray(card2,half);
  printf("Sum Chosen by Millionaire is: %d\n",ans);
  t1 = clock();
  fillSums(card,cardsums,0,0,half);
   printf("Cards\n");
  fillSums(card2,cardsums2,0,0,half);
   printf("Cards\n");
  mergeSort(cardsums,0,combi-1);
  //quicksort(cardsums2,0,combi-1);
   printf("Cards\n");
  mergeSort(cardsums2,0,combi-1);
  //quicksort(cardsums2,0,combi-1);
   printf("Cards\n");
  //printArray(cardsums,combi);
  //printArray(cardsums2,combi);
  for(i=combi-1;i>=0;i--)
  {
	  for(j=0;j<combi;j++)
	  {
		  if((cardsums[i]+cardsums2[j])==ans)
		  {
			printf("Sum Found: %d,%d\n",(cardsums[i]+cardsums2[j]),ans);
			found++;
			break;
		  }
		  else if((cardsums[i]+cardsums2[j])>ans)
			break;
	  }
	   if(found>0)
			break;
  }
  if(found==0)
	printf("Sum Not Found\n");
  t2 = clock();
  printf("Done within ### %f sec . ###\n", (double) (t2-t1)/CLOCKS_PER_SEC);
  free(cardsums);
  free(cardsums2);
  free(card);
  free(card2);
  return 0;
}