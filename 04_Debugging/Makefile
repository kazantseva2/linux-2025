range: range.c
	cc -O0 -g range.c -o range

test: range debug1.gdb debug2.gdb
	@echo "===== Запуск теста 1 ====="
	@gdb --batch --quiet -x debug1.gdb ./range | grep "^@@@" > out1.txt
	@diff -u ref1.txt out1.txt && echo "Тест пройден!" || (echo "Тест провален!")

	@echo "\n===== Запуск теста 2 ====="
	@gdb --batch --quiet -x debug2.gdb ./range | grep "^@@@" > out2.txt
	@diff -u ref2.txt out2.txt && echo "Тест пройден!" || (echo "Тест провален!")

clean:
	rm -f range out1.txt out2.txt