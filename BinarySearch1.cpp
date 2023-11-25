#include<iostream>
#include<vector>

using namespace std;

int solution1(vector<int>arr,int target)
{
// Given a sorted array of n elements and a target ‘x’. Find the last occurrence of ‘x’ in the array. If ‘x’
// does not exist return -1.
// Input 1: arr[] = {1,2,3,3,4,4,4,5} , x = 4
// Output 1: 6

    int si = 0;
    int ei= arr.size();

    while(si<ei)
    {
        int mid = (si+ei)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid]>target) ei = mid - 1;
        else si = mid + 1;        
    }

    return -1;


}


int solution2(vector<int>arr)
{
    int ei = arr.size();
    int si = 0;
    int ri  = -1;

    while(si<ei)
    {
        int mid = (si+ei)/2;
        if(arr[mid] == 0)
        {
            ri = mid;
            si = mid+1;
        }

        else //(arr[mid] == 1)
        ei = mid-1;    
    }

    if(ri == -1) return arr.size();
    return arr.size()-(ri+1);

}
void input(vector<int>&arr,int size)
{
    for(int i=0; i<size; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<endl;
}
void input(vector<vector<int>>&arr)
{
   

    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[0].size(); j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<endl;
}

int solution3(vector<vector<int>>arr)
{
    int maxNumber = -1;
    int maxRow = -1;

    for(int i=0; i<arr.size(); i++)
    {
        int temp = solution2(arr[i]);
        cout<<temp<<" "<<endl;

        if(temp>maxNumber)
        {
            maxNumber = temp;
            maxRow = i;
        }
    }

    if(maxRow == -1) return 0;
    return maxRow;
}
void display(vector<int>arr)
{
    for(int i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}


void solution4(vector<int>arr,int size)
{
    input(arr,size);

    for(int i=0; i<size ; i++)
    {
        if(arr[0] ==arr[arr[0]])
        {
            cout<<arr[0]<<" is dublicate : ";
        }
        
        else{
            swap(arr[0],arr[arr[0]]);
        }
    }

}
int main()
{
    system("CLS");
    string s = " Question 1 : iven a sorted array of n elements and a target x . Find the last occurrence of x in the array. If x does not exist return -1.";
    cout<<s;
    cout<<"\nEnter size : ";
    int size;
     cin>>size;
    vector<int>arr;
    cout<<"Enter Elements : ";
    input(arr,size);
    int target;
    cout<<"Enter target : ";
    cin>>target;
    int idx = solution1(arr,target);
    cout<<"Answere 1: "<<idx;
    cout<<"\nEnter y for next : ";
    char ch;
    cin>>ch;
    system("CLS");
    cout<<endl;



    
    string s3 =" Given a matrix having 0-1 only where each row is sorted in increasing order, find the row with themaximum number of 1’s.";
    cout<<s3;
    cout<<endl;
    cout<<"Enter row and coloum of Matrix  : ";
    int r,c;
    cin>>r>>c;
    vector<vector<int>>matrix(r,vector<int>(c,0));
    cout<<matrix.size()<<" "<<matrix[0].size()<<endl;
    cout<<"Enter Elements of Matrix  : ";
    input(matrix);
    cout<<"done";
    cout<<"Answere 3: "<<solution3(matrix);
    cout<<"\nEnter y for next : ";
  
    cin>>ch;
    system("CLS");
    cout<<endl;

    string s4 = "Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n]inclusive in sorted order.";
    cout<<s4;
    cout<<"Enter size : ";
    cin>>size;
    solution4(arr,size);
}
