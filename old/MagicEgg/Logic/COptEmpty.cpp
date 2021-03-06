#include "COptEmpty.h"

#include "../Data/CVarGroupDefined.h"

void COptEmpty::Work(const TMU *pTMU)
{
	try
	{
		CField *pField = null_v;
		v_ *p = m_pVariable->Value((obj_ &)pField);

		if (p)
		{
			TFieldGroup *pFieldGroup = (TFieldGroup *)(obj_)*p;

			if (pFieldGroup->nSize && pFieldGroup->pData)
			{
				_DEL_ARR(pFieldGroup->pData);
				pFieldGroup->nSize = 0;
			}
		}

		p = m_pVariable->Value(pTMU);
		p->empty();
	}
	catch (...)
	{
		throw;
	}
}



