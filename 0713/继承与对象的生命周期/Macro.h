#pragma once

#define PROPERTY(__TYPE__, __FUNC__, __MEMBER__) \
public: \
	__TYPE__ Get##__FUNC__() const \
	{ \
		return __MEMBER__; \
	} \
	void Set##__FUNC__(__TYPE__ val) \
	{ \
		__MEMBER__ = val; \
	}

