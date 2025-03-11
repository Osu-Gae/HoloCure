#pragma once
template<typename T>
class CAbstractFactory
{
	// √ﬂªÛ ∆—≈‰∏Æ

	static shared_ptr<T> Create()
	{
		shared_ptr<T> pInstance = make_shared<T>();
		pInstance->Initialize();
		return pInstance;
	}
	
};

