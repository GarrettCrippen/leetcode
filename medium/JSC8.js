/**
 * @param {Function} fn
 * @return {Function}
 */

//once() like an event listener, but responds to event only once
//function syntax: access to arguments variable(iterable)


//seperate closure is created for each function call, so 
//after the first call hasbeencalled = true and it returns undefined

//more "correct" way is use fn.apply(this,args) to bind it to the current context
var once = function(fn) {
    let hasbeencalled = false;
    return function(...args){
        if(!hasbeencalled){
        hasbeencalled=true;
        return fn(...args);}
        else{
            //this is not neccessary, but more clear(it is implicitly returned also)
            return undefined;
        }
    }
};


/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */