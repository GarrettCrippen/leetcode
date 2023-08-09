/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */

//javaScript objects are mappings of strings(keys) to values
    //access: 
        //1. object.obj.x
        //2. object["obj"], used when key isn't valid variable name
        //3. const{num,str} = object
            //this is called Destructuring(comparable to unpacking)
                //[a,b] = [10,20] is valid or [a, b, ...rest] = [10, 20, 30, 40, 50];
                //for...in , for...of , function parameters, result of regex, any iterable
                //can swamp some [a,b]=[b,a]
                //can ignore some [a, , b] = [1,2,3]
                //can assign new variable names or change default values
                //optionally, can supply default values

//objects
    //initializer object = {
    //   propertyValue1: 5
    //   2: 6
    //   "propertyValue3": 7
    //}      

    //constructor function or (See class syntax)
         //Capitlize is the convention ex. function Car()
         //use this to assign member variables
         //create instance with keyword new or use Object.create!

    //methods defined as property of the object
    //getters and setters have keyword get() or set(1 param)

    //property accessors
        //string or symbol(found at runtime)
        //undefined properties return undefined

        //enumerate
            //for...in
            //keys.myObj(myObj)
            //getOwnPropertyNames(myObj) 
        
        //can DELETE non inherited properties
        //can provide inheritance through protype keyword __proto__:

//Proxy
    //override default behavior of objects
        //data validation, developer tool


        var createCounter = function(init) {
            let n = init;
            return {
                increment: () => ++n,
                decrement: () => --n,
                reset: () => (n = init),
            }
        };
        
        /**
         * const counter = createCounter(5)
         * counter.increment(); // 6
         * counter.reset(); // 5
         * counter.decrement(); // 4
         */