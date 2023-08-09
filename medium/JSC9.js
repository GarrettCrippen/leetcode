/**
 * @param {Function} fn
 */

//function memoize() allows your to store function call results
    //only works for pure functions, same output given same inputs
    //does not work with side effects, i.e. uploading to database
//use cases:
    //cache website files
    //render react components
    //cache api calls
        //data staleness(returning old network reponse instead of updates)
            //send request if value changed
            // use a websocket to subscribe to changes in db
            //give value time until expiration

//limitations in dp => cannot just use memoize on unmemoized functions ex. fib
//we don't care about the input function type name, just memoize regardless
function memoize(fn) {
    //can create var or let map = Object();
    let sum = {};
    return function(...args) {
        //we could also use JSON.stringy(args)
        const key = args.join('-');
        //console.log(fn.name);

            //can use keyword in
            if(sum.hasOwnProperty(key))
                return sum[key];
            else{
                sum[key] = fn(...args);
                return sum[key];
            }
        

    }
}

//optimize by using numeric constraints + function apply, cause making key is expensive
    //key = a+(b*100001); or Function.apply cause never more than 2 args

//one liner using ?? nullish coalescing operator:
//var memoize = (fn, cache = {}) => (...args) => cache[args.join()] ?? (cache[args.join()] = fn(...args)) 
/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */