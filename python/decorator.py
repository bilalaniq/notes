from datetime import datetime
import time

def logger(fun):
    def wrapper():
        print("-" *20)
        print(">Execution started {}".format(datetime.today().strftime("%Y-%m-%d %H:%M:%S")))
        fun()
        print(">Execution finished {}".format(datetime.today().strftime("%Y-%m-%d %H:%M:%S")))
        print("-" *20)
    return wrapper

@logger
def demo_fun():
        print("executing task")
        time.sleep(2)
        print("task finished")

demo_fun()


logger(demo_fun())
# this will give the same output as above

# we can also give arguments to the decorator function

def logger_with_args(fun):
        def wrapper(*args, **kwargs):
            print("-" *20)
            print(">Execution started {}".format(datetime.today().strftime("%Y-%m-%d %H:%M:%S")))
            fun(*args, **kwargs)
            print(">Execution finished {}".format(datetime.today().strftime("%Y-%m-%d %H:%M:%S")))
            print("-" *20)
        return wrapper

@logger_with_args
def demo_fun_with_args(sleep_time):
    print("executing task")
    print("sleeping for {} seconds".format(sleep_time))
    time.sleep(sleep_time)
    print("task finished")

demo_fun_with_args(3)


