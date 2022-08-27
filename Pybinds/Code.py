import fast_math
import timeit


count_F = 0
count_V = 0

def Expression(ls,n):
	global count_F
	global count_V

	p = ls[0]
	q = ls[1]
	print("------")
	print(f'p = {fast_math.ToVF(p)} ; q = {fast_math.ToVF(q)}')

	# ~q
	exp1 = fast_math.Not(q)
	print(f'~q = {fast_math.ToVF(exp1)}')

	# (p V ~q)
	exp2 = fast_math.Or(p,exp1)
	print(f'(p V ~q) = {fast_math.ToVF(exp2)}')

	# ~ (p V ~q)
	exp3 = fast_math.Not(exp2)
	print(f'~ (p V ~q) = {fast_math.ToVF(exp3)}')
	if not exp1:
		count_F += 1
	else:
		count_V += 1

	if not exp2:
		count_F += 1
	else:
		count_V += 1

	if not exp3:
		count_F += 1
	else:
		count_V += 1

fast_math.TableDynamic(Expression,2)
print(f'Count F : {count_F}')

print(f'Count V : {count_V}')

timeit.timeit("[(a, b) for a in (1, 3, 5) for b in (2, 4, 6)]")