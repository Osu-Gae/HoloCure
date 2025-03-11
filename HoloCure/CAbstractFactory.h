#pragma once
template<typename T>
class CAbstractFactory
{
	// �߻� ���丮

	static shared_ptr<T> Create()
	{
		shared_ptr<T> pInstance = make_shared<T>();
		pInstance->Initialize();
		return pInstance;
	}
	
};

