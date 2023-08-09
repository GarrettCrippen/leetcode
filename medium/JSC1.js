/**
 * @return {Function}
 */

//anonymous function that takes any number of args
//this is an example of a higher order function, i.e. a function that takes another function!
var createHelloWorld = function(){
    //another valid way would be [     var createHelloWorld = ()=> {      ]
          //prefered for anonymous functions
          //not allowed to use function before it was declared (hoisting)
          //can't be used for this, super and arguments or used as a constructor
      
              //rest arguments ...args = all passed arguments as an array
      return function(...args) {
  
          //either returns a value or "undefined", 
          //if a single line, then can omit return statement
          return "Hello World";
      }
  };
  
  /**
   * const f = createHelloWorld();
   * f(); // "Hello World"
   */