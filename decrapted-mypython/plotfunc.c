#include </root/anaconda3/include/python3.11/Python.h>
#include <stdio.h>

// Declare the global variable
PyObject *pModule = NULL;

void Py_initial_FNLGNLHNL_code() {
    // Initialize the NumPy API
    // import_array(); // Added line // 如果需要使用numpy，则需要调用import_array()

    // Add . to the Python path
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/workspace/Ubuntu/SGWBxCMB/class_public/mypython')");

    // Import plotfunc and its functions
    pModule = PyImport_ImportModule("plotfunc");
    if (pModule == NULL) {
        fprintf(stderr, "Failed to import plotfunc module in Py_initial_FNLGNLHNL_code\n");
        PyErr_Print();  // Print the error details
        return;
    }

    // Call the readdata function without any arguments
    PyObject *pReaddataFunc = PyObject_GetAttrString(pModule, "readdata");
    if (PyCallable_Check(pReaddataFunc)) {
        PyObject *pArgs = PyTuple_New(1);
        PyTuple_SetItem(pArgs, 0, Py_BuildValue("i", 1));
        PyObject *pValue = PyObject_CallObject(pReaddataFunc, pArgs);
        if (pValue != NULL) {
            printf("Result of readdata call in Py_initial_FNLGNLHNL_code: %ld\n", PyLong_AsLong(pValue));
            Py_DECREF(pValue);
        } else {
            PyErr_Print();
        }
        Py_DECREF(pArgs);
    } else {
        printf("Call readdata failed in Py_initial_FNLGNLHNL_code\n");
    }
    
    // Clean up
    Py_DECREF(pReaddataFunc);
}

PyObject* call_C_call_total(double k_, double sigma, double A, double FNL) {
    // Call the C_call_total function
    PyObject *pFunc = PyObject_GetAttrString(pModule, "C_call_total");
    if (PyCallable_Check(pFunc)) {
        PyObject *pArgs = PyTuple_New(4);
        PyTuple_SetItem(pArgs, 0, Py_BuildValue("d", k_)); // k_
        PyTuple_SetItem(pArgs, 1, Py_BuildValue("d", sigma)); // sigma
        PyTuple_SetItem(pArgs, 2, Py_BuildValue("d", A)); // A
        PyTuple_SetItem(pArgs, 3, Py_BuildValue("d", FNL)); // FNL

        PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            if (PyFloat_Check(pValue)) {
                double result = PyFloat_AsDouble(pValue);
                Py_DECREF(pValue);
                Py_DECREF(pFunc);
                return Py_BuildValue("d", result);
            } else {
                printf("Result of call: Unexpected return type\n");
            }
            Py_DECREF(pValue);
        } else {
            PyErr_Print();
        }
        Py_DECREF(pFunc);
    } else {
        printf("Call C_call_total failed\n");
    }

    return NULL;
}

PyObject* call_C_call_ob(double k_, double sigma, double A, double FNL) {
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();

    // Call the C_call_ob function
    // printf("this is in call_C_call_ob\n");
    PyObject *pFunc = PyObject_GetAttrString(pModule, "C_call_ob");
    if (PyCallable_Check(pFunc)) {
        PyObject *pArgs = PyTuple_New(4);
        PyTuple_SetItem(pArgs, 0, Py_BuildValue("d", k_)); // k_
        PyTuple_SetItem(pArgs, 1, Py_BuildValue("d", sigma)); // sigma
        PyTuple_SetItem(pArgs, 2, Py_BuildValue("d", A)); // A
        PyTuple_SetItem(pArgs, 3, Py_BuildValue("d", FNL)); // FNL

        PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            if (PyFloat_Check(pValue)) {
                double result = PyFloat_AsDouble(pValue);
                Py_DECREF(pValue);
                Py_DECREF(pFunc);
                return Py_BuildValue("d", result);
            } else {
                printf("Result of call: Unexpected return type\n");
            }
            Py_DECREF(pValue);
        } else {
            PyErr_Print();
        }
        Py_DECREF(pFunc);
    } else {
        printf("Call C_call_ob failed\n");
    }
    PyGILState_Release(gstate);
    return NULL;
}

PyObject* call_C_call_ng1_over_total(double k_, double sigma, double A, double FNL) {
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();
    // Call the C_call_ng1 function
    PyObject *pFunc = PyObject_GetAttrString(pModule, "C_call_ng1_over_total");
    if (PyCallable_Check(pFunc)) {
        PyObject *pArgs = PyTuple_New(4);
        PyTuple_SetItem(pArgs, 0, Py_BuildValue("d", k_)); // k_
        PyTuple_SetItem(pArgs, 1, Py_BuildValue("d", sigma)); // sigma
        PyTuple_SetItem(pArgs, 2, Py_BuildValue("d", A)); // A
        PyTuple_SetItem(pArgs, 3, Py_BuildValue("d", FNL)); // FNL

        PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            if (PyFloat_Check(pValue)) {
                double result = PyFloat_AsDouble(pValue);
                Py_DECREF(pValue);
                Py_DECREF(pFunc);
                return Py_BuildValue("d", result);
            } else {
                printf("Result of call: Unexpected return type\n");
            }
            Py_DECREF(pValue);
        } else {
            PyErr_Print();
        }
        Py_DECREF(pFunc);
    } else {
        printf("Call C_call_ng1_over_total failed\n");
    }
    PyGILState_Release(gstate);
    return NULL;
}

PyObject* call_C_call_B(double f) {
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();

    // Call the C_call_ng1 function
    PyObject *pFunc = PyObject_GetAttrString(pModule, "C_call_B");
    if (PyCallable_Check(pFunc)) {
        PyObject *pArgs = PyTuple_New(1);
        PyTuple_SetItem(pArgs, 0, Py_BuildValue("d", f)); // f

        PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            if (PyFloat_Check(pValue)) {
                double result = PyFloat_AsDouble(pValue);
                Py_DECREF(pValue);
                Py_DECREF(pFunc);
                return Py_BuildValue("d", result);
            } else {
                printf("Result of call: Unexpected return type\n");
            }
            Py_DECREF(pValue);
        } else {
            PyErr_Print();
        }
        Py_DECREF(pFunc);
    } else {
        printf("Call C_call_B failed\n");
    }

    PyGILState_Release(gstate);
    return NULL;
}

int main(int argc, char *argv[]) {
    // Initialize the Python Interpreter
    Py_Initialize();

    // Call the new function
    Py_initial_FNLGNLHNL_code();

    // Define parameters
    double k_ = 1.0;
    double sigma = 1.0;
    double A = 3.6e-3;
    double FNL = 5.0;

    // Call the C_call_total function and get the result
    // PyObject *result = call_C_call_total(k_, sigma, A, FNL);

    // if (result != NULL) {
    //     double total = PyFloat_AsDouble(result);
    //     printf("total: %e\n", total);
    //     Py_DECREF(result);
    // } else {
    //     printf("Call C_call_total failed\n");
    // }

    // Call the C_call_ob function and get the result
    PyObject *result2 = call_C_call_ob(k_, sigma, A, FNL);

    if (result2 != NULL) {
        double ob = PyFloat_AsDouble(result2);
        Py_DECREF(result2);
    } else {
        printf("Call C_call_ob failed\n");
    }

    // Call the C_call_ng1 function and get the result
    PyObject *result3 = call_C_call_ng1_over_total(k_, sigma, A, FNL);

    if (result3 != NULL) {
        double ng1 = PyFloat_AsDouble(result3);
        Py_DECREF(result3);
    } else {
        printf("Call C_call_ng1 failed\n");
    }

    // Call the C_call_B function and get the result
    double f = 1.0;
    PyObject *result4 = call_C_call_B(f);

    if (result4 != NULL) {
        double B = PyFloat_AsDouble(result4);
        Py_DECREF(result4);
    } else {
        printf("Call C_call_B failed\n");
    }

    // Clean up and close the Python Interpreter
    Py_DECREF(pModule);
    Py_Finalize();

    return 0;
}