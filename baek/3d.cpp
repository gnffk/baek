int gnObjects; //���� ��ü�� ����
CObject* gpObjects; //���� ��ü���� �迭
CCamera* gpCamera;  //ī�޶� ��ü
void RenderObjects()
{
    for (int i = 0; i < gnObjects; i++) Draw(&gpObjects[i]);
}
void Draw(CObject* pObject)
{
    CVertex vtxPrevious;
    for (int i = 0; i < pObject->pMesh->nFaces; i++)
    {
        CPolygon* pPolygon = &pObject->pMesh->pFaces[i];
        for (int j = 0; j < pPolygon->nVertices; j++)
        {
            CVertex v = Transform(pPolygon->pVertices[j], pObject);
            if (j != 0) Draw2DLine(vtxPrevious.x, vtxPrevious.y, v.x,
                v.y);
            vtxPrevious = v;
        }
    }
}
void Draw2DLine(float x0, float y0, float x, float y)
{
    HDC hDC = GetDC(...);
    ::MoveToEx(hDC, (long)x0, (long)y0, NULL);
    ::LineTo(hDC, (long)x, (long)y);
    ::ReleaseDC(...);
}