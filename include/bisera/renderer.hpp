#pragma once

namespace bisera {
    class Renderer {
        public:
            virtual void clear() = 0;
            virtual void swapBuffers() = 0;
    };
}
