//
// Created by Дима Щипицын on 27/09/2021.
//

#include "Raycaster.hpp"

static int		inspect(const std::vector<std::string> &map, const Raycaster::Ray &ray, float t_sin, float t_cos)
{
    int x;
    int y;

    if (ray.side)
    {
        y = t_sin > 0 ? ray.pos.y : ray.pos.y - 1;
        x = ray.pos.x;
    }
    else
    {
        x = t_cos > 0 ? ray.pos.x : ray.pos.x - 1;
        y = ray.pos.y;
    }
    if (map[y][x] == '1')
        return (1);
    return (0);
}

static Raycaster::Ray	cast_a_ray(const sf::Vector2f &startPoint, float t_sin, float t_cos, const std::vector<std::string> &map)
{
    Raycaster::Ray	a;
    Raycaster::Ray	b;
    Raycaster::Ray	ray;

    ray.pos.x = startPoint.x;
    ray.pos.y = startPoint.y;
    while (1)
    {
        a.pos.x = t_cos > 0 ? floor(ray.pos.x + 1) - ray.pos.x : ceil(ray.pos.x - 1) - ray.pos.x;
        a.pos.y = a.pos.x * (t_sin / t_cos);
        b.pos.y = t_sin > 0 ? floor(ray.pos.y + 1) - ray.pos.y : ceil(ray.pos.y - 1) - ray.pos.y;
        b.pos.x = b.pos.y * (t_cos / t_sin);
        a.len = a.pos.x * a.pos.x + a.pos.y * a.pos.y;
        b.len = b.pos.x * b.pos.x + b.pos.y * b.pos.y;
        ray.pos.x = (a.len < b.len) ? ray.pos.x + a.pos.x : ray.pos.x + b.pos.x;
        ray.pos.y = (a.len < b.len) ? ray.pos.y + a.pos.y : ray.pos.y + b.pos.y;
        ray.side = (a.len < b.len) ? 0 : 1;
        if (inspect(map, ray, t_sin, t_cos))
        {
            ray.len = (ray.pos.x - startPoint.x) * t_cos + (ray.pos.y - startPoint.y) * t_sin;
            return (ray);
        }
    }
}

Raycaster::Raycaster(int nRays) : rays_(nRays), nRays_(nRays) {}

Raycaster::~Raycaster() {

}

void Raycaster::raycasting(const std::vector<std::string> &map, GameActor &actor)
{
    double	angle;
    double	t_sin;
    double	t_cos;
    Ray     ray;
    double  fov;
    double  step_ray;

    fov = 55 * M_PI / (double)180;
    step_ray = fov / static_cast<float>(nRays_);
    angle = actor.angle() - fov / 2;
    for (int i = 0; i < nRays_; ++i) {
        angle += step_ray;
        t_sin = sin(angle);
        t_cos = cos(angle);
        rays_[i] = cast_a_ray(actor.position(), t_sin, t_cos, map);
        rays_[i].len *= cos(angle - actor.angle());
    }
}

const Raycaster::Ray& Raycaster::getRay(int n) const {
    return rays_[n];
}

int Raycaster::getNRays() const {
    return nRays_;
}
