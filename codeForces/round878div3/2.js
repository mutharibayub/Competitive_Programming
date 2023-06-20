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

function main() {
    const tt = parseInt(readline());
    for(let t=0;t<tt;t++){
        let [n, k] = readline().split(" ").map(x=>parseInt(x));
        let ans = 0;
        for(let i=Math.min(30, k-1);i>=0;i--){
            let num=1<<i;
            if(num<=n){
                ans += 1<<i;
                n-=num;
            }
        }
        console.log(ans+1);
    }

}