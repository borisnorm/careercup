# http://www.careercup.com/question?id=5485521224597504
#!/usr/bin/python

def flatten(container, new_container):
	for element in container:
		if isinstance(element, list) or isinstance(element, tuple) or isinstance(element, set):
			flatten(element, new_container)
		else:
			new_container.append(element)
	pass
	
if __name__ == '__main__':
	a = [1, 2.3, [3, [1, 222]], (4, 111, 0), "string", set([1, "hello", 3.33])]
	res = []
	flatten(a, res)
	print(res)
	pass
	