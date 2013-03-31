#include <string>
#include <vector>

class QGLShaderProgram;

class TriMesh
{
    public:
        /// Read mesh from the given file
        bool readFile(const std::string& fileName);

        /// Draw mesh using current OpenGL context
        void drawFaces(QGLShaderProgram& prog);
        void drawEdges(QGLShaderProgram& prog);

    private:
        static void makeSmoothNormals(std::vector<float>& normals,
                                      const std::vector<double>& verts,
                                      const std::vector<unsigned int>& faces);

        static void makeEdges(std::vector<unsigned int>& edges,
                              const std::vector<unsigned int>& faces);

        std::vector<double> m_verts;
        std::vector<float> m_normals;
        std::vector<unsigned int> m_faces;
        std::vector<unsigned int> m_edges;
};