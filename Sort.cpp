#include<bits/stdc++.h>
using namespace std;
int t = 0;
//插入排序
//从第一个数开始，后面一个数插入到前面已有数的对应位置
void insertionSort(vector<int> &nums){
    int len = nums.size();
    for(int i = 0; i < len; ++i){
        for(int j = i; j > 0 && nums[j] < nums[j-1]; --j){
            swap(nums[j], nums[j-1]);
        }
    }
}

//选择排序
//从第一个位置开始，找其后面数的最小值，和第一个位置交换，每次都取当前最小值向前填充
void selectionSort(vector<int> &nums){
    int len = nums.size();
    for(int i = 0; i < len-1; ++i){
        int mn = i;
        for(int j = i+1; j < len; ++j){
            if(nums[j] < nums[mn]){
                mn = j;
            }
        }
        swap(nums[mn], nums[i]);
    }
}

//冒泡排序
//只需冒n-1轮，若有一轮没有冒泡，则可以直接退出
void bubbleSort(vector<int> &nums){
    int len = nums.size();
    for(int i = 1; i < len; ++i){
        bool swapFlag = false;
        for(int j = 1; j < len - i + 1; ++j){
            t++;
            if(nums[j] < nums[j-1]){
                swap(nums[j], nums[j-1]);
                swapFlag = true;
            }
        }
        if(!swapFlag) break;
    }
}

//优化：用last代替交换flag，last为0代表没有交换过，每次n替换为last可以节省已排好序的数字
void bubbleSort2(vector<int> &nums){
    int len = nums.size();
    int n = len;
    for(int i = 1; i < len; ++i){
        int last = 0;
        for(int j = 1; j < n; ++j){
            t++;
            if(nums[j] < nums[j-1]){
                swap(nums[j], nums[j-1]);
                last = j;
            }
        }
        n = last;
        if(!n) break;
    }
}
//快速排序
//找出每段区间小于p位置的所有数，并用l指针存储，再把p交换回来左右两边继续向下排序
void quickSort(vector<int> &nums, int left, int right){
    if(left >= right) return;
    int len = nums.size();
    int p = left + rand()%(right - left + 1);
    swap(nums[p], nums[right]);
    int l = left - 1;
    for(int i = left; i < right; ++i){
        if(nums[i] < nums[right]){
            l++;
            swap(nums[l], nums[i]);
        }
    }
    p = l+1;
    swap(nums[right], nums[p]);
    quickSort(nums, left, p - 1);
    quickSort(nums, p + 1, right);
}

//归并排序
//先二分到最小然后向上排序，借助temp存储左右子树一起排序后的结果
void mergeSort(vector<int> &nums, vector<int> &temp, int left, int right){
    if(left >= right) return;
    int mid = left + (right - left)/2;
    mergeSort(nums, temp, left, mid);
    mergeSort(nums, temp, mid+1, right);
    int l = left, r = mid + 1, i = l;
    while(l <= mid || r <= right){
        if((l <= mid && nums[l] < nums[r]) || r > right){
            temp[i++] = nums[l++];
        }
        else{
            temp[i++] = nums[r++];
        }
    }
    for(int i = left; i <= right; ++i){
        nums[i] = temp[i];
    }
}

// 堆排序
// 1、先初始化堆成为大顶堆，即从最后一个父节点开始，一直到0根节点，对每个子树进行调整，结果即为大顶堆
// 2、将堆顶元素与堆底未排序元素进行交换，自上而下调整之后重复
void heapajust(vector<int> &vec, int start, int end);
void heapsort(vector<int> &vec){
    int n = vec.size();
    for(int i = n/2 - 1; i >= 0; --i){
        heapajust(vec, i, n - 1);
    }
    while(n-1){
        swap(vec[0], vec[n-1]);
        heapajust(vec, 0, n-2);
        n--;
    }
}

void heapajust(vector<int> &vec, int start, int end){
    int child = 2*start + 1;
    int father = start;
    while(child <= end){
        if(child + 1 <= end && vec[child+1] > vec[child]){
            child++;
        }
        if(vec[child] > vec[father]){
            swap(vec[father], vec[child]);
        }
        else return;
        father = child,
        child = father*2+1;
    }
}

int main(){
    vector<int> vec({5,2,6,4,1,3});
    int len = vec.size();
    
    //insertionSort(vec);

    //selectionSort(vec);

    //bubbleSort3(vec);
    //cout<<t<<',';

    //quickSort(vec, 0, len-1);

    // vector<int> temp(len-1, 0);
    // mergeSort(vec, temp, 0, len-1);

    heapsort(vec);
    for(auto i : vec) cout<<i<<',';
}