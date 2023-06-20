'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readline() {
    return inputString[currentLine++];
}

function check(arr, diff) {
    let last = arr[0];
    let count = 1;
    for(let i=1;i<arr.length;i++) {
        if(arr[i]-last>2*diff) {
            last = arr[i];
            count++;
        }
    }
    return count <= 3;
}

function main() {
    const tt = parseInt(readline());
    for(let t=0;t<tt;t++) {
        let n = parseInt(readline());
        let arr = readline().split(" ").map(x=>parseInt(x));

        arr.sort((a, b)=>a-b);

        let ans = -1;
        for(let jump=Math.floor(1e9+7);jump>0;jump=Math.floor(jump/2)) {
            while(ans+jump<1e9+7 && !check(arr, ans+jump)) {
                ans += jump;
            }
        }
        console.log(ans+1);
    }

}