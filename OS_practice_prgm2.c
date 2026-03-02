#include<stdio.h>
int main(){
    int n;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the key to search:");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(key==arr[i]){
            printf("The element is present at position %d\n",i);
        }
    }

}
