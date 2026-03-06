d=stack2

compile: main.cpp
	g++ main.cpp -o stack1

run: ./stack1
	./stack1 

compile2: main2.cpp
	g++ main2.cpp -o stack2

test1: ./$(d)
	./$(d) {[]}[] {[]] [] {{  }}

test2: ./$(d)
	./$(d) {[]}[]

test3: ./$(d)
	./$(d) {[]

test4: ./$(d)
	./$(d) {[}]

test5: ./$(d)
	./$(d) {{

test6: ./$(d)
	./$(d) {{}}
