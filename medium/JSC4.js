/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

//callback is a function passed as arg to another function
    //core algorithm same => reuse code


    var map = function(arr, fn) {
        for(i in arr){
            // console.log(typeof i);
            // console.log(typeof arr[i]);
            arr[i]= fn(arr[i],parseInt(i,10));
        }
        return arr;
    };