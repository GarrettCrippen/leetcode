/**
 * @param {Function} fn
 * @return {Function}
 */


//currying = function with sequence of arguments into function with sequence of functions
    //better code reusability and flexibilty
    //event handling => create event handlers while core is generic
        //getElementById("button").addEventListener("click",button1Handler);
    //more specific api calls
    //higher order functions


//args is constructed from nextArgs, so 1 -> 2 -> 3 then stop when equal to fn.length
//at max arg then return full function

//can use bind method to handle the this context
    //same, just use fn.apply() and curried.bind(this,...args)
    var curry = function(fn) {
        return function curried(...args) {
            //console.log(args.length);
            if(args.length >= fn.length){
                return fn(...args);
            }
    
    
            return (...nextArgs) => curried(...args,...nextArgs);
        };
    };
    
    /**
     * function sum(a, b) { return a + b; }
     * const csum = curry(sum);
     * csum(1)(2) // 3
     */