#pragma once
#ifdef OVEJAVEGANA_EXPORT
#define OVEJAVEGANA_API __declspec(dllexport)
#else
#define OVEJAVEGANA_API __declspec(dllimport)
#endif
#pragma once
