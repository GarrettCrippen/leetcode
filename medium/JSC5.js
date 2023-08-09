/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

//logical operators: false = 
//false, forms of zero, NaN or 0/0, "",null,undefined
    // || returns first value if truthy, otherwise second value
    // && returns firstvalue if falsey, otherwise return second value
    // Nullish Coalesing:  ?? same as || except null and underfined or only falsy

//we can use recursive funciton
var filter = function(arr, fn) {
    //create a new array to store
    var farr = []
    for(let i = 0; i<arr.length; i++){
        if(fn(arr[i],i))
            farr.push(arr[i]);
    }
    return farr;
};

//optionally, we can do inplace by having a let size =0 and then popping after