// MazeView - renders a maze in 3d with OpenGL

#ifndef _MAZE_VIEW_H_
#define _MAZE_VIEW_H_

#include "Maze.h"
#include "Drawable.h"

#include <vector>
using namespace std;

#include "ImathVec.h"
using namespace Imath;


class MazeView : public Drawable {
    public:
        // size.x - x component of the 2d maze
        // size.y - y compenent of the 2d maze
        // size.z - how tall the walls go up
        MazeView(const Maze &maze, const Vec3<float> &pos,
            const Vec3<float> &size, int startX, int startY,
            int finishX, int finishY, int reqX, int reqY);
        ~MazeView();

        // get the 2d coordinates of a 3d location
        const Vec2<int> coordinates(const Vec3<float> & location) const;

        // get the wall dimensions
        const Vec3<float> sectorSize() const;

        // send a sphere and a delta and return a vector position with
        // the sphere in a valid location as close to the wanted destination
        // as possible
        const Vec3<float> resolveSphereCollision(Vec3<float> pos, 
            float radius, Vec3<float> delta ) const;

    protected:
        // render with opengl
        void render();

    private:
        const Maze & m_maze;
        const Vec3<float> m_pos;
        const Vec3<float> m_size;
        Vec3<float> m_sectorSize;
        Vec3<float> m_postSize;
        vector< Vec3<float> > m_posts;

        int m_startX, m_startY;
        int m_finishX, m_finishY;
        int m_reqX, m_reqY;

        void cuboid(Vec3<float> basePt1, Vec3<float> basePt2,
            Vec3<float> basePt3, Vec3<float> basePt4, float height);
        void cylinder(Vec3<float> basePt, float radius, float height,
            int numSides = 20);

        void vertWall(Vec3<float> loc);
        void horizWall(Vec3<float> loc);
        void renderPost(Vec3<float> loc);
        Vec3<float> getCornerLoc(int x, int y);
        void createPosts();

        bool rectCollide(float obj1x1, float obj1y1, float obj1x2,
            float obj1y2, float obj2x1, float obj2y1, float obj2x2,
            float obj2y2) const;
        bool rectCollideUnsafe(float obj1x1, float obj1y1, float obj1x2,
            float obj1y2, float obj2x1, float obj2y1, float obj2x2,
            float obj2y2) const;

        Vec3<float> getSectorLoc(int x, int y) const;
};

#endif

