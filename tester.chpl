iter distribSerialIterator() {
	on Locales[1] do yield 1;
}

for x in distribSerialIterator() do writeln(x);
