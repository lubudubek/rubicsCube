#pragma once

struct OnlineParams
{
	float fovy   {  0.4f };
	float near   {  0.6f };
	float far    { 50.0f };
	float aspect { 1.37f };

	float transformZ {  -16.0f };
	float rotateX    {   0.4f };
	float rotateY    {  -0.6f };

	float rotateXstatic{ 0.4f };
	float rotateYstatic{ -0.6f };

	glm::vec3 fTriangle{};
	glm::vec3 sTriangle{};
	glm::vec3 tTriangle{};
};