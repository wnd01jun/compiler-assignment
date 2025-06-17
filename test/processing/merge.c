
int sorted[8];
 
void merge(int *data, int start, int mid, int end){
    int i,j,k,t;
    i = start;
    j = mid+1;
    k = start;
    if (start == end) {
        return;
    }
    while (i <= mid && j <= end) {
        if(data[i] <= data[j]){
            sorted[k] = data[i];
            i++;
        }else{
            sorted[k] = data[j];
            j++;
        }
        k++;
    }
    if(i > mid) {
        for(t = j; t<=end; t++){
            sorted[k] = data[t];
            k++;
        }
    }
    else {
        for(t = i; t<=mid; t++){
            sorted[k] = data[t];
            k++;
        }
    }
    

    for(t=start; t<=end; t++){
        data[t] = sorted[t];
    } 
} 
 
void merge_sort(int *data, int start, int end){
    if(start < end){
        int mid;
        mid = (start + end) / 2;
        merge_sort(data, start, mid);
        merge_sort(data, mid+1, end);
        merge(data, start, mid, end);
    }
}
 
int main(void){
 
    int data[8], i;
    data[0] = 3;
    data[1] = 6;
    data[2] = 7;
    data[3] = 1;
    data[4] = 2;
    data[5] = 4;
    data[6] = 8;
    data[7] = 5;
    
    merge_sort(data, 0, 7);
    
    for(i=0; i<8; i++){
        printf("%d ", data[i]);
    } 
    return 0;
}​
