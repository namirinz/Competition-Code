function maxSubsetProduct(arr){
    var isHave0 = false;
    var total_pos = 1,total_neg = 1,min_neg = -99999999;
    var count_pos = 0,count_neg = 0;
    let len = arr.length;
    for (let i=0;i<len;i++){
        if (arr[i] > 0){
            count_pos++;
            total_pos *= arr[i];
        }else if (arr[i] == 0){
            isHave0 = true;
        }else {
            count_neg++;
            total_neg *= arr[i];
            if (arr[i] >= min_neg){
                min_neg = arr[i];
            }
        }
    }    
    if (count_pos <= 1 && count_neg <= 1){
        if (isHave0){
            return 0;
        }else {
            return arr[0]*arr[1];
        }
    }else if ( count_neg % 2 == 0){
        return total_neg*total_pos;
    }else {
        return (total_neg/min_neg)*total_pos;
    }
}

var arr = [-2, -3, 0, 2, 3];

console.log(maxSubsetProduct(arr));