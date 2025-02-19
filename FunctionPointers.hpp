#ifndef __FUNCTION_POINTERS__
#define __FUNCTION_POINTERS__


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method cannot require any parameters.
 */
template <typename C>
using MethodPtr = void (C::*) ();


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires one parameter.
 */
template <typename C, typename P1>
using MethodPtr1P = void (C::*) (P1 p1);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires two parameters.
 */
template <typename C, typename P1,
                      typename P2>
using MethodPtr2P = void (C::*) (P1 p1, P2 p2);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires three parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3>
using MethodPtr3P = void (C::*) (P1 p1, P2 p2, P3 p3);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires four parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3,
                      typename P4>
using MethodPtr4P = void (C::*) (P1 p1, P2 p2, P3 p3, P4 p4);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires five parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3,
                      typename P4,
                      typename P5>
using MethodPtr5P = void (C::*) (P1 p1, P2 p2, P3 p3, P4 p4,
                                 P5 p5);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires six parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3,
                      typename P4,
                      typename P5,
                      typename P6>
using MethodPtr6P = void (C::*) (P1 p1, P2 p2, P3 p3, P4 p4,
                                 P5 p5, P6 p6);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires seven parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3,
                      typename P4,
                      typename P5,
                      typename P6,
                      typename P7>
using MethodPtr7P = void (C::*) (P1 p1, P2 p2, P3 p3, P4 p4,
                                 P5 p5, P6 p6, P7 p7);


/**
 * Stores a pointer to a method belonging to class C.
 * To refer to a class method, use format &ClassName:MethodName.
 * 
 * The method requires eight parameters.
 */
template <typename C, typename P1,
                      typename P2,
                      typename P3,
                      typename P4,
                      typename P5,
                      typename P6,
                      typename P7,
                      typename P8>
using MethodPtr8P = void (C::*) (P1 p1, P2 p2, P3 p3, P4 p4,
                                 P5 p5, P6 p6, P7 p7, P8 p8);


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr
 */
template <typename InstanceClass>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr<InstanceClass> methodPtr)
{
    (instance.*methodPtr) ();
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr1P<InstanceClass, P1> methodPtr,
                    P1 p1)
{
    (instance.*methodPtr) (p1);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr2P<InstanceClass, P1, P2> methodPtr,
                    P1 p1, P2 p2)
{
    (instance.*methodPtr) (p1, p2);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr3P<InstanceClass, P1, P2, P3> methodPtr,
                    P1 p1, P2 p2, P3 p3)
{
    (instance.*methodPtr) (p1, p2, p3);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3, typename P4>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr4P<InstanceClass, P1, P2, P3, P4> methodPtr,
                    P1 p1, P2 p2, P3 p3, P4 p4)
{
    (instance.*methodPtr) (p1, p2, p3, p4);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3, typename P4,
                                  typename P5>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr5P<InstanceClass, P1, P2, P3, P4,
                                               P5> methodPtr,
                    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
{
    (instance.*methodPtr) (p1, p2, p3, p4, p5);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3, typename P4,
                                  typename P5, typename P6>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr6P<InstanceClass, P1, P2, P3, P4,
                                               P5, P6> methodPtr,
                    P1 p1, P2 p2, P3 p3, P4 p4, 
                    P5 p5, P6 p6)
{
    (instance.*methodPtr) (p1, p2, p3, p4, p5, p6);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3, typename P4,
                                  typename P5, typename P6,
                                  typename P7>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr7P<InstanceClass, P1, P2, P3, P4,
                                               P5, P6, P7> methodPtr,
                    P1 p1, P2 p2, P3 p3, P4 p4, 
                    P5 p5, P6 p6, P7 p7)
{
    (instance.*methodPtr) (p1, p2, p3, p4, p5, p6, p7);
}


/**
 * Calls a method of an object of type InstanceClass
 * using the pointer methodPtr and the provided parameters.
 */
template <typename InstanceClass, typename P1, typename P2,
                                  typename P3, typename P4,
                                  typename P5, typename P6,
                                  typename P7, typename P8>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr8P<InstanceClass, P1, P2, P3, P4,
                                               P5, P6, P7, P8> methodPtr,
                    P1 p1, P2 p2, P3 p3, P4 p4, 
                    P5 p5, P6 p6, P7 p7, P8 p8)
{
    (instance.*methodPtr) (p1, p2, p3, p4, p5, p6, p7, p8);
}

#endif










