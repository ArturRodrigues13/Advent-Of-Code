import hashlib

entrada = input()
copia = ""
i = 0

while(True):
	copia = entrada
	copia += str(i)
	copia = copia.encode("utf-8")
	copia = hashlib.md5(copia).hexdigest()
	if copia[0:6] == "000000":
		break

	i +=1

print(copia)
print(i)
