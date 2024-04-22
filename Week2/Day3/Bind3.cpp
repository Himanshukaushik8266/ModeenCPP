/*
    Week 2:
    1) Function Pointers
    2) Function wrapper
        - A way to capture any callable in a type-erased way
        - It can be used for following
            -   Pass a callable as a parameter
            -   Return a callable as a value
            -   Save functions as "values" in container/variables 
    3) Reference Wrapper 
        - It is an object that internally stores a reference to "something"
        - It uses pointer to refernce conversion internally
        - It can be replacement for raw reference everywhere in the code.
        - rValues cannot be converted into refernce wrapper.
        - Replacement for lvalue raw references.
    4) Bind function (std::bind())
        - Used to create a partial function.
        - A function some parameters are already fixed
        - Redsign or tweak the sequence of parameters by swapping or repositioning them as per requirement
*/