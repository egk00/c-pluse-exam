#include "stdafx.h"
#include "ObjectList.h"
using namespace System;

int main()
{
	IntListUser intListUser;
	intListUser.PushBack(1);
	intListUser.PushBack(2);
	intListUser.PushBack(3);
	intListUser.Write(IntList::GetIntList());
    return 0;
}
