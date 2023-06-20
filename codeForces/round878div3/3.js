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
        let [n, k, q] = readline().split(" ").map(x=>parseInt(x));
        let arr = readline().split(" ").map(x=>parseInt(x));
        let ans = 0, consec = 0;
        for(let i=0;i<n;i++){
            if(arr[i]<=q){
                consec++;
                ans += consec>=k?consec-k+1:0;
            }
            else{
                consec = 0;
            }
        }
        console.log(ans);
    }

}