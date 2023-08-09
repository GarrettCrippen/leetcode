/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */

//debounce useful for api calls
var debounce = function(fn, t) {
    //a function that runs after delay

    //cleartimeout if calls happen before delay
    let id = undefined;
    return function(...args) {
        clearTimeout(id);
        id = setTimeout(() => fn(...args),t)
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */