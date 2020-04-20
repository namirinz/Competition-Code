/*
    Giving an array that have more than
    1 item and can contain negative or postive integer
    or zero 
    
    Find the maximum multiple of 2 number
    **Condition** : the algorithm should run less than or
    equal to O(nlogn)

    Time Complexity: O(n) :)
*/
function findMaxProduct(arr){
    var minMinus1=0,minMinus2=0;
    var maxPos1=-1,maxPos2=-1;
    var len = arr.length;
    for (let i=0;i<len;i++){
        if (arr[i] >= maxPos1 && arr[i] >= 0){
            maxPos2 = maxPos1;
            maxPos1 = arr[i];
        }else if (arr[i] >= maxPos2 && arr[i] >= 0){
            maxPos2 = arr[i];
        }else if (arr[i] <= minMinus1 && arr[i] < 0){
            minMinus2 = minMinus1;
            minMinus1 = arr[i];
        }else if (arr[i] <= minMinus2 && arr[i] < 0){
            minMinus2 = arr[i];
        }
    }
    if (minMinus1 != 0 && minMinus2 != 0 && maxPos1 != -1 && maxPos2 != -1){
        //console.log(" 2max 2min ");
        return Math.max(minMinus1*minMinus2,maxPos1*maxPos2);
    }else if (maxPos2 == -1 && minMinus1 != 0 && minMinus2 != 0){
        //console.log(" 2min 1 max ");
        return minMinus1*minMinus2;   
    }else if (minMinus2 == 0 && maxPos1 != -1 && maxPos2 != -1 ){
        //console.log(" 2max 1min ");
        return maxPos1*maxPos2;
    }else {
        if (arr[0] == 0 || arr[1] == 0) return 0;
        return arr[0]*arr[1];
    }
    
}

var arr1 = [123,-1526,-4,99,123123,999]
console.log(findMaxProduct(arr1))