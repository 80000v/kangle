#ifndef KSRCSACL_H
#define KSRCSACL_H
#include "KMultiAcl.h"
#include "KXml.h"
#include "utils.h"
class KSrcsAcl: public KMultiAcl {
public:
	KSrcsAcl() {
		icase_can_change = false;
		seticase(false);
	}
	virtual ~KSrcsAcl() {
	}
	KAcl *newInstance() {
		return new KSrcsAcl();
	}
	const char *getName() {
		return "srcs";
	}
	bool match(KHttpRequest *rq, KHttpObject *obj) {
		return KMultiAcl::match(rq->getClientIp());
	}
protected:
	char *transferItem(char *file)
	{
		//KFileName::tripDir3(file,PATH_SPLIT_CHAR);
		return file;
	}
};
#endif
