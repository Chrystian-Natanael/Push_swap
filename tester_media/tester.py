#!/usr/bin/env python3

import random
import subprocess
import sys

# n_values = [500]
n_values = [3, 5, 50, 100, 500]
# n_values = range(11)
# n_values = [x for x in range(3, 101) if x == 3 or x == 5 or x % 10 == 0]
range_start = -2**31
range_end = 2**31 - 1

for n in n_values:
	outputs = []
	max_sequence = []
	min_sequence = []
	print(f"For n = {n}:", flush=True)
	print(f"\n\nFor n = {n}:\n", file=sys.stderr, flush=True)

	for _ in range(100):
		print(".", end="", flush=True, file=sys.stderr)
		numbers = random.sample(range(range_start, range_end + 1), n)
		numbers_string = ' '.join(map(str, numbers))

		# output = subprocess.check_output("valgrind -q --track-origins=yes --leak-check=full --show-leak-kinds=all ./push_swap " + numbers_string, shell=True)
		output = subprocess.check_output("./push_swap " + numbers_string, shell=True)
		output = output.decode()

		try:
			checker = subprocess.check_output(f'./push_swap {numbers_string} | valgrind -q --track-origins=yes --leak-check=full --show-leak-kinds=all ./checker {random.sample(range(range_start, range_end + 1), n)}', shell=True)
		except:
			print(f"Error: {numbers_string}")
			exit()
		# checker = subprocess.check_output(f'./push_swap {numbers_string} | ./checker {numbers_string}', shell=True)
		# checker = checker.decode()

		print(checker, flush=True)
		if (checker == "KO\n"):
			print(f"ko sequence: {numbers_string}")
			exit()

		num_newlines = output.count('\n')
		outputs.append(num_newlines)

		if num_newlines == max(outputs):
			max_sequence = numbers
		if num_newlines == min(outputs):
			min_sequence = numbers

	averages = sum(outputs) / len(outputs)
	maximum = max(outputs)
	minimum = min(outputs)

	print("Average:", averages)
	print("Maximum:", maximum)
	print("Minimum:", minimum)
	print()
	print("Maximum Sequence:", *max_sequence)
	print()
	print("Minimum Sequence:", *min_sequence)
	print()
	print(flush=True)