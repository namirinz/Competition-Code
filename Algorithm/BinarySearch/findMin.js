/*
    Find the minimum number in sorted array
    that maybe has some move
    EX: 1,2,3,4,5 -> 3,4,5,1,2

    by using Binary Search
    Time Complexity: O(log n)
*/

function findMin(arr){
    left = 0;
    right = arr.length-1;
    while (true){
        mid = left+Math.floor((right-left)/2);
        if (mid == left){
            if (arr[left]<arr[right]){
                //console.log(" left ",left,arr[left]);
                return arr[left];
            }else {
                //console.log(" right ",right,arr[right]);
                return arr[right];
            }
        }else if (arr[mid] > arr[left] && arr[mid] > arr[right]){
            if (arr[right] > arr[left]){
                //console.log(" most right",right,mid);
                right = mid;
            }else {
                //console.log(" most left ",left,mid);
                left = mid
            }
        }else if (arr[mid] > arr[right]){
            //console.log(" left more ",left,mid);
            left = mid;
        }else if (arr[mid] > arr[left]){
            //console.log(" right more ",right,mid);
            right = mid;
        }else {
            if (arr[left] < arr[right]){
                //console.log(" less left ",left,mid);
                left = mid;
            }else {
                //console.log(" less right",right,mid)
                right = mid;
            }
        }
    }   
}

var arr = [5,6,7,3,4];
console.log(findMin(arr));