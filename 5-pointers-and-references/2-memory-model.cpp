/*
new : 
    - 'new' operator is used for allocating memory during runtime
    - allocated memory rematins available untill we explicitely deallocate it using 'delete' operator
    - if it fails to allocate memort it throws an bad_alloc error

    # syntax
        1> dataType* ptr = new dataType;
        2> dataType* ptr = new dataType(initializer);
        3> dataType* ptr = new dataType[size];

nothrow:
    - It returns a NULL value if new fails to allocate memory but doesn't throw any error

    # syntax
        1> dataType* ptr = new(nothrow) dataType;

delete: 
    - It is used for deallocating memory during runtime.

    # syntax
        1> delete ptr;
        2> delete[] ptr;
*/
