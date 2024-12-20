

#include<bits/stdc++.h>
using namespace std;

void print1(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<endl;
    print1(i+1,n);
}

void print2(int n){
    if(n<1){
        return;
    }
    print2(n-1);
    cout<<n<<endl;
    return;
}

void print3(int n){
    if(n<1){
        return;
    }
    cout<<n<<endl;
    print3(n-1);
}

int numberSum (int n){
    if(n==1){
        return 1;
    }
    return n + numberSum(n-1);
}

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n * factorial(n-1);
}

void printArray(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArray (int arr[],int n){
    int i=0,j=n-1;
    
    while(j>i){
        swap(arr[i++],arr[j--]);
    }
    
}

void recursiveReverseArray(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    
    swap(arr[start],arr[end]);
    
    recursiveReverseArray(arr,start+1,end-1);
}

bool isPalindrome(string s){
    int left = 0, right = s.length()-1;
    
    while(left < right){
        if(s[left++] != s[right--]){
            return false;
        }
    }
    return true;
}

void fibonacci(int n){ // assuing n>2
    int fib[n+1];
    fib[0]=0;fib[1]=1;
    
    for(int i=2;i<=n;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    printArray(fib,n+1);
}



int main()
{
	int n =6;
	int arr[] = {6,5,4,3,2,1};
	string s = "abcdcba";
	string s1 = "abcd";
	//print1(1,n);
	//print2(n);
	//print3(n);
	
	//cout<<numberSum(n)<<endl;  use formula -> n * (n+1)/2
	
	//cout<<factorial(n)<<endl;
	
	//reverseArray(arr,n);
	//printArray(arr,n);
	
	//recursiveReverseArray(arr,0,n-1);
	//printArray(arr,n);
	
	//cout<<isPalindrome(s1);
	
	//fibonacci(n);
	
	//recursiveFibonacci(n);


}
