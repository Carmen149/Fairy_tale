#include "Camera.hpp"

namespace gps {

    //Camera constructor
    Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 cameraUp) {
        this->cameraPosition = cameraPosition; //vectorul de pozitie al camerei
        this->cameraTarget = cameraTarget; //vectorul de origine al scenei
        this->cameraUpDirection = cameraUp;
        this->cameraFrontDirection = glm::normalize(cameraPosition - cameraTarget); 
        this->cameraRightDirection = glm::normalize(glm::cross(cameraUpDirection, cameraFrontDirection));

        //TODO - Update the rest of camera parameters

    }

    //return the view matrix, using the glm::lookAt() function
    glm::mat4 Camera::getViewMatrix() {
        return glm::lookAt(cameraPosition, cameraTarget, cameraUpDirection);
    }
    glm::mat4 Camera::getViewMatrix_2() {
        return glm::lookAt(cameraPosition, cameraPosition + cameraFrontDirection, cameraUpDirection);
    }
   /* glm::mat4 Camera::getViewMatrix() {
        return glm::lookAt(cameraPosition, cameraPosition + cameraFrontDirection, cameraUpDirection);
    }*/
    void Camera:: update(glm::vec3 cameraPosition, glm::vec3 cameraFront)
    {
        this->cameraPosition = cameraPosition;
        this->cameraFrontDirection = cameraFront;
    }
    glm::vec3 Camera::getCameraPosition() {
        return this->cameraPosition;
    }
    //update the camera internal parameters following a camera move event
    void Camera::move(MOVE_DIRECTION direction, float speed) {
        //TODO
        if (direction == MOVE_FORWARD) {
            cameraPosition += speed * cameraFrontDirection;
            cameraTarget += cameraFrontDirection * speed;
        }
        if (direction == MOVE_BACKWARD) {
            cameraPosition -= cameraFrontDirection * speed;
            cameraTarget -= cameraFrontDirection * speed;
        }
        if (direction == MOVE_RIGHT) {
            cameraPosition += cameraRightDirection * speed;
            cameraTarget += cameraRightDirection * speed;
        }
        if (direction == MOVE_LEFT) {
            //if(cameraPosition.x>=-275.728821)
            cameraPosition -= cameraRightDirection * speed;
            cameraTarget -= cameraRightDirection * speed;
        }
        if (direction == MOVE_UP) {
            cameraPosition.y += 0.8 * speed;
            cameraTarget.y += 0.8 * speed;
        }
        if (direction == MOVE_DOWN) {
            //if(cameraPosition.y>= -53.999966 )
            cameraPosition.y -= 0.8 * speed;
            cameraTarget.y -= 0.8 * speed;
        }
    }

    //update the camera internal parameters following a camera rotate event
    //yaw - camera rotation around the y axis
    //pitch - camera rotation around the x axis
    void Camera::rotate(float pitch, float yaw) {
        //TODO
        //pitch -unghiul care arată cât de mult privim în sus sau în jos
        //yaw-valoarea de rotire care reprezintă mărimea pe care o căutăm la stânga sau la dreapta
        glm::vec3 aux;
        aux.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        aux.y = sin(glm::radians(pitch));
        aux.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

        cameraFrontDirection = glm::normalize(aux);
        //cameraFrontDirection = aux;
        this->cameraRightDirection = glm::normalize(glm::cross(this->cameraFrontDirection, cameraUpDirection));
        this->cameraTarget = cameraPosition + cameraFrontDirection;

    }
    void Camera::setCameraPos(glm::vec3 cameraPos)
    { 
        this->cameraPosition = cameraPos;
    }
    void Camera::setCameraTarget(glm::vec3 cameraT)
    {
        this->cameraTarget = cameraT;
    }
    glm::vec3 Camera::getCameraTarget()
    {
        return this->cameraTarget;
    }
    glm::vec3 Camera::getCameraFrontDirection()
    {
        return this->cameraFrontDirection;
    }
}