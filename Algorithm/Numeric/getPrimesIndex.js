function getPrimesIndex(arr){
    var prime = new Array(100005).fill(0)
    prime[0] = -1;
    prime[1] = -1;
    var index = 0;
    for (let i=2;i<=100005;i++){
        if (prime[i] != -1){
            prime[i] = index;
            index++;
            for (let j=i*2;j<=100005;j+=i){
                prime[j] = -1;
            }
        }
    }
    var len = arr.length;
    var ans = [];
    for (let i=0;i<len;i++){
        ans.push(prime[arr[i]])
    }
    return ans;
}

var arr = [0,1,2]
console.log(getPrimesIndex(arr));