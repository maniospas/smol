@include std.core
@include std.mem

def Employee(nominal, str name, str surname)
    return @args

def employee_test(@mut ContiguousMemory mem)
    @mut emp = Employee[mem].expect(1)
    print(emp[0].name)
    emp.push(nominal.Employee("me".str(), "mario".str()))

service main()
    @mut buf = Heap.allocate(4.KB())
    @mut b1 = u64[buf]
    b1.push(1)
    b1.push(2)
    employee_test(buf)  // SHOULD CREATE AN ERROR
