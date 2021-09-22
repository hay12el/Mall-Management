#include "Clothing.h"

Clothing::Clothing() : Chain(), importer("") {}

Clothing::Clothing(string name, string importer) : Chain(name), importer(importer) {}

Clothing::Clothing(const Clothing& obj) : Chain(obj), importer(obj.importer)
{
}

void Clothing::print()
{
	cout << "Importer: " << this->importer << endl;
}

Clothing::~Clothing()
{
}
